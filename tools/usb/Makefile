# SPDX-License-Identifier: GPL-2.0
# Makefile for USB tools

PTHREAD_LIBS = -lpthread
WARNINGS = -Wall -Wextra
CFLAGS = $(WARNINGS) -g -Wno-address-of-packed-member -I../include
LDFLAGS = $(PTHREAD_LIBS)

all: testusb ffs-test
%: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) testusb ffs-test
