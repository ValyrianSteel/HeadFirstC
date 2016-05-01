encrypt.o: ../encrypt.c
	gcc -c ../encrypt.c -o ../obj/encrypt.o
checksum: ../checksum.c
	gcc -c ../checksum.c -o ../obj/checksum.o

libhfsecurity.a: ../obj/encrypt.o ../obj/checksum.o
	ar -rcs ../lib/libhfsecurity.a ../obj/encrypt.o ../obj/checksum.o
bank_vault: bank_vault.c ../lib/libhfsecurity.a
	gcc bank_vault.c -I../ -L../lib -lhfsecurity -o bank_vault
