

TEST_LINKFLAGS = -L$(CONTROLLER) -l controller \
			$(LIBS)
TEST_RPATHS = -Wl,-rpath -Wl,$(CONTROLLER)

tests/test-keras_mnist_short.x: tests/test-keras_mnist_short.o \
                                libcontroller.so
	$(CC) -o $(@) $(<) $(CFLAGS) \
		$(TEST_LINKFLAGS) \
		$(TEST_RPATHS)
