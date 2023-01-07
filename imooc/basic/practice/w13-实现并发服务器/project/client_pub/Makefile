OBJS := sem.o shmfifo.o shm.o client.o main.o

client_pub:$(OBJS)
	@gcc $^ -o $@ -lpthread
	@echo "Done."

%.o:%.c
	@gcc -c $< -o $@

clean:
	@rm *.o client_pub
	@echo "Clean."
