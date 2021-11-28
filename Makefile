CXXFLAGS= g++ -std=c++14 -g -Wall

text0 = 
text1 = Se procederá a compilar la práctica...
text2 = Modo de empleo:
text3 = ./estval
text4 = Se ha eliminado el fichero ejecutable.
text5 = Se ha eliminado el fichero de salida.

F1 = main.cc

ODIR = src/

PROGRAM = estval

all: GCO

Inicio:
	@echo $(text1)

GCO: Inicio
	$(CXXFLAGS) $(ODIR)$(F1) -o $(PROGRAM)
	@echo $(text0)
	@echo $(text2) $(text3)$(PROGRAM)

clean:
	rm -rf $(PROGRAM)
	@echo $(text0)
	@echo $(text4)