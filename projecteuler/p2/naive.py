ant2 = 1
ant = 2

sum = 2
while True:
    current = ant+ant2
    if current > 4000000:
        break
    if current % 2 == 0:
        sum += current
    ant2, ant = ant, current

print(sum)
