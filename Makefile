# Makefile para jogo gráfico, 
# Feito por Leonardo da Silva Camargo
# GRR 20203903


#Variaveis
CFLAGS = -std=c99 -Wall -g
LDLIBS = -lm
PACKAGEFLAGS = pkg-config
ALLEGRO5FLAGS = allegro-5 allegro_font-5 allegro_ttf-5 allegro_image-5 allegro_audio-5 allegro_acodec-5 --libs --cflags

#object-files
objects = main.o movement.o allegro_manager.o map.o fall.o falling_list.o menu_commands.o verify_fall.o

#default execution
all: boulderdash

boulderdash: $(objects)
	gcc $(CFLAGS) $(objects) $(LDLIBS) -o boulderdash $$($(PACKAGEFLAGS) $(ALLEGRO5FLAGS))

main.o: main.c
	cc -c main.c $(CFLAGS)

movement.o: movement.c movement.h
	cc -c movement.c $(CFLAGS)

map.o: map.c map.h
	cc -c map.c $(CFLAGS)

fall.o: fall.c fall.h
	cc -c fall.c $(CFLAGS)
falling_list.o: falling_list.c falling_list.h
	cc -c falling_list.c $(CFLAGS)
menu_commands.o: menu_commands.c menu_commands.h
	cc -c menu_commands.c $(CFLAGS)
verify_fall.o: verify_fall.c verify_fall.h
	cc -c verify_fall.c $(CFLAGS)
clean:
	rm -f *.o

purge: clean
	rm -f boulderdash
