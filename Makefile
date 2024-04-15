CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
LDLIBS = -lgtest -lgtest_main -lpthread
INCLUDES = -Imodel -Icontroller
GREEN = \033[32m
RESET = \033[0m

# Source files
TEST_SOURCES = tests/tests.cc
CALC_SRCS = src/model/model.cc src/model/model.h src/controller/calcController.cc src/controller/calcController.h
BANK_SRCS = src/model/credModel.cc src/model/credModel.h src/model/deposModel.h

# Output binaries
TEST_OUTPUT = tests/tests

all: clean uninstall install open

install: 
	@echo "$(GREEN)Starting installation$(RESET)"
	mkdir build && cd build && cmake ../src/CMakeLists.txt && make
	mv build/SmartCalc.app ~/Desktop
	rm -rf build
	@echo "$(GREEN)**********************"
	@echo "Installed successfully"
	@echo "**********************$(RESET)"

open:
	open ~/Desktop/SmartCalc.app

uninstall:
	@rm -rf ~/Desktop/SmartCalc.app build

tests: $(TEST_SOURCES) $(CALC_SRCS) $(BANK_SRCS)
	@$(CXX) -std=c++17 $(INCLUDES) $^ -o $(TEST_OUTPUT) $(LDLIBS)
	./$(TEST_OUTPUT)


format:
	@find . -type f -name "*.cc" -exec clang-format -style=Google -i {} \;
	@find . -type f -name "*.cpp" -exec clang-format -style=Google -i {} \;
	@find . -type f -name "*.h" -exec clang-format -style=Google -i {} \;

dist: clean
	@mkdir -p dist/src
	@cp -r Makefile docu.html dist/src
	@cp -r src dist/src/SmartCalc
	@tar -czvf SmartCalc.tar.gz dist/src
	@rm -rf dist

dvi:
	open docu.html 

valgrind: 
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all $(TEST_OUTPUT)

clean:
	@rm -rf $(TEST_OUTPUT) *.o *.a a.out *.css *.gch build SmartCalc.tar.gz

