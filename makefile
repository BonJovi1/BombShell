bombshell: \
			cd.o \
			clock.o \
			echo.o \
			jobs.o \
			ls.o \
			lsa.o \
			lsl.o \
			lsla.o \
			main.o \
			others.o \
			pinfo.o \
			prompt.o \
			pwd.o \
			remindme.o \
			setenv.o \
			unsetenv.o \
			execute.o \
			parse.o \
			redirect.o \
			fg.o

	$(CC) -g -o bombshell $^

clean:
	@rm -f *.o bombshell

cd.o: headers.h src/cd.c
	$(CC) -g -c src/cd.c

clock.o: headers.h src/clock.c
	$(CC) -g -c src/clock.c

echo.o: headers.h src/echo.c
	$(CC) -g -c src/echo.c

jobs.o: headers.h src/jobs.c
	$(CC) -g -c src/jobs.c

ls.o: headers.h src/ls.c
	$(CC) -g -c src/ls.c

lsa.o: headers.h src/lsa.c
	$(CC) -g -c src/lsa.c

lsl.o: headers.h src/lsl.c
	$(CC) -g -c src/lsl.c

lsla.o: headers.h src/lsla.c
	$(CC) -g -c src/lsla.c

main.o: headers.h main.c
	$(CC) -g -c -w main.c

others.o: headers.h src/others.c
	$(CC) -g -c src/others.c

pinfo.o: headers.h src/pinfo.c
	$(CC) -g -c src/pinfo.c

prompt.o: headers.h src/prompt.c
	$(CC) -g -c src/prompt.c

pwd.o: headers.h src/pwd.c
	$(CC) -g -c src/pwd.c

remindme.o: headers.h src/remindme.c
	$(CC) -g -c src/remindme.c

setenv.o: headers.h src/setenv.c
	$(CC) -g -c src/setenv.c

unsetenv.o: headers.h src/unsetenv.c
	$(CC) -g -c src/unsetenv.c

execute.o: headers.h src/execute.c
	$(CC) -g -c src/execute.c

parse.o: headers.h src/parse.c
	$(CC) -g -c src/parse.c

redirect.o: headers.h src/redirect.c
	$(CC) -g -c src/redirect.c

fg.o: headers.h src/fg.c
	$(CC) -g -c src/fg.c



