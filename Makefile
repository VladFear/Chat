SUBDIRS = server client

.PHONY: all clean client server

all:
	@for a in $(SUBDIRS); do \
	echo "make $$a"; \
	$(MAKE) -C $$a $$a.out; done

client:
	$(MAKE) -C client all

server:
	$(MAKE) -C server all

clean:
	@for a in $(SUBDIRS); do \
	echo "make $$a"; \
	$(MAKE) -C $$a clean; done
