APP=sorting

__start__: obj ./${APP}
	@rm -f core.* core; ./${APP}

obj:
	mkdir obj

${APP}: obj/main.o
	@echo
	@echo compiling...
	@echo
	@g++ -o ${APP} obj/main.o
	@echo done	
	@echo
obj/main.o: src/main.cpp  inc/mergesort.hh inc/quicksort.hh inc/introsort.hh
	@g++  -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

	
	
clear:
	@echo
	@echo clearing...
	@echo
	@rm -f obj/* ./${APP} core.* core
	@rmdir obj/
	@echo
	@echo clearing complited
	@echo
	