MAKEFLAGS += -s
SHELL := /bin/bash
CC = gcc
CFLAGS = -Wall -O2 -Wno-unused-result
SRC = codigo/main.c codigo/pacote.c codigo/lista.c codigo/drone.c codigo/galpao.c
EXE = programa.exe

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXE)

run: all
	@read -p "Modo (teclado/arquivo): " modo; \
	if [ "$$modo" = "teclado" ]; then \
		echo "=== Executando em modo teclado (stdin) ==="; \
		./$(EXE); \
	elif [ "$$modo" = "arquivo" ]; then \
		read -p "Escolha arquivo (teste1/teste2/teste3/teste4/all): " file; \
		case $$file in \
    		all) make run10 && make run15 && make run20 && make run30 ;; \
    		teste1) make run10 ;; \
    		teste2) make run15 ;; \
    		teste3) make run20 ;; \
    		teste4) make run30 ;; \
			*) echo "Arquivo não reconhecido: $$file"; exit 1 ;; \
		esac; \
	else \
		echo "Modo não reconhecido: $$modo"; exit 1; \
	fi

run10: all
	@echo "==== Executando teste N=10 ===="
	@./$(EXE) testes/teste1.txt
	@echo ""

run15: all
	@echo "==== Executando teste N=15 ===="
	@./$(EXE) testes/teste2.txt
	@echo ""

run20: all
	@echo "==== Executando teste N=20 ===="
	@./$(EXE) testes/teste3.txt
	@echo ""

run30: all
	@echo "==== Executando teste N=30 ===="
	@./$(EXE) testes/teste4.txt
	@echo ""

clean:
	rm -f $(EXE)
