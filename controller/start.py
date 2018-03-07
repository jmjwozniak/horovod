import os
os.environ["HOROVOD_COMM"] = os.getenv("COMM")
execfile("examples/keras_mnist.py")
print("KERAS MNIST DONE 1")
execfile("examples/keras_mnist.py")
print("KERAS MNIST DONE 2")
