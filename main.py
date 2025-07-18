from machine import Pin
from time import sleep_ms

pins = [13,14,15,25]

timings = [66, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16,
           18, 8, 18, 16, 18, 8, 18, 16, 33, 45, 33, 16, 16, 91, 18, 16, 33, 41, 37, 8, 18, 29, 16, 16, 18, 16, 16, 16,
           18, 16, 16, 16, 18, 16, 16, 16, 18, 8, 18, 16, 18, 8, 18, 16, 18, 8, 18, 16, 18, 8, 18, 16, 16, 70, 100]

pins = [Pin(gpio,Pin.OUT) for gpio in pins]


def run_timings(off):
    v = 0
    for t in timings:
        for p in pins:
            p.value(v)
        sleep_ms(t+ (-off if v else off))
        v = 1-v
    print(v)

while True: run_timings(0)
