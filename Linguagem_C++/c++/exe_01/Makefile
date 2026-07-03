clean:

	@echo "limpando objetos"
	rm -f ./bin/app ./obj/obj.o
	@echo ""

tads:

	@echo "criando objetos"
	g++ -c ./src/source.cpp -I ./include/ -o ./obj/obj.o
	@echo ""

exec:

	@echo "criando binário do programa"
	g++ ./app/main.cpp -I ./include/ ./obj/obj.o -o ./bin/app
	@echo ""

run:

	@echo "executando programa"
	./bin/app
	@echo ""

all: clean tads exec run