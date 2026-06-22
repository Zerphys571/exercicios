BIN = ./bin
SRC = ./src
OBJ = ./obj
INCLUDE = ./include
APPS = ./apps
DEBUG = ./src/debug

all: clean tads exec debug run

clean:
	@echo ""
	rm -f ${OBJ}/obj.o ${BIN}/app ${DEBUG}/debug_app
	@echo ""

tads:
	@echo "Criando objetos"
	gcc -c ${SRC}/src.c -I ${INCLUDE}/ -o ${OBJ}/obj.o
	@echo ""
    
exec:
	@echo "Criando executáveis"
	gcc ${APPS}/main.c -I ${INCLUDE}/ ${OBJ}/obj.o -o ${BIN}/app
	@echo ""

debug:
	@echo "Criando debug"
	gcc -g ${APPS}/main.c -I ${INCLUDE}/ ${OBJ}/obj.o -o ${DEBUG}/debug_app
	@echo ""

run:
	@echo "Iniciando aplicativo"
	@echo ""
	${BIN}/app
	@echo ""