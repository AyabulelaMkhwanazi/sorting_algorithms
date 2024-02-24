include update.mk

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g
TARGET = a
SCRIPT = 0-main.c

FILE = 0-bubble_sort.c 
COMPILE_SHELL = compile.sh
GCC_FILES = $(shell bash $(COMPILE_SHELL))
LATEST_MAIN = $(shell ls -t *-main.c | head -n 1)

compile:
		@chmod u+x $(COMPILE_SHELL)
		./$(COMPILE_SHELL)

$(TARGET): $(LATEST_MAIN) $(GCC_FILES)
		$(CC) $(CFLAGS) -o $@ $^

.PHONY: all test git style compile

all: test count style

test: $(TARGET)
		printf "\rRunning $(FILE) ..."; \
		sleep 2; \
		printf "\r%$${COLUMNS}s\r"; \
		@./$(TARGET)
		@echo

git:
	@if [ -f .commit_msg ]; then \
		NEW_MSG=$$(cat .commit_msg); \
	else \
		echo "Enter a commit message: "; \
		read NEW_MSG; \
		fi; \
		git add .;\
		git commit -m "$$NEW_MSG"; \
		git push

clean:
		rm -f $(TARGET)

count:
	@printf "\rLine count: \n";
	@OUTPUT=$$(wc -l $(FILE)); \
	echo $$OUTPUT; \
	sleep 3; \
	printf "\033[1A"; \
	printf "\r%$${COLUMNS}s\r"; \
	printf "\033[1A"; \
	printf "\r%$${COLUMNS}s\r";


style:
	@printf "\rChecking $(FILE) for style errors:\n"
	@sleep 1;
	@printf "\r%$${COLUMNS}s\r";
	@bash -c '\
	OUTPUT=$$(betty $(FILE)); \
	if [ -n "$$OUTPUT" ]; then \
		echo -e "\n$$OUTPUT"; \
	else \
		echo "No errors"; \
		sleep 1; \
		printf "\033[1A"; \
		printf "\r%$${COLUMNS}s\r"; \
		printf "\033[1A"; \
		printf "\r%$${COLUMNS}s\r"; \
	fi'
