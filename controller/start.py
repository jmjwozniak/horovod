import os
os.environ["HOROVOD_COMM"] = os.getenv("COMM")
execfile("examples/keras_mnist.py")
