imagen.png: ejemplo.dat grafica.py
	python grafica.py

%.dat : a.out
	./a.out 

a.out: DanielSalazar_ejercicio29.cpp
	g++ DanielSalazar_ejercicio29.cpp

clean:
	rm -rf a.out ejemplo.dat plot.png *~