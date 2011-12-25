FLAGS= -g -Wall
OUT=mkprcs

all: output

compile: clean
	@for cpps in *.cpp ; \
		do g++ -c $(FLAGS) $$cpps ;\
	done

output: compile
	g++ *.o  $(FLAGS) -o $(OUT)

clean:
	rm -rf *.o $(OUT)
