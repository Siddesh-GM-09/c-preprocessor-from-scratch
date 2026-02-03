target=main.o remove_comments.o
CC=gcc
stage:$(target)
	$(CC) $(target) -o stage
main.o:main.c
	$(CC) -c main.c
remove_comments.o:remove_comments.c
	$(CC) -c remove_comments.c
clear:
	@echo Cleaning Object File
	@del /Q *.o 2>nul