import struct
import matplotlib.pyplot as plt

c ='cmake-build-release/out.raw_mono_d'
cpp ='cmake-build-release/mixed.out'
with open(cpp, 'rb') as f:
    bytes = f.read()

fmt = 'd' * (len(bytes) / 8)
x = list(struct.unpack(fmt, bytes))
plt.plot(x)
plt.show()
pass
