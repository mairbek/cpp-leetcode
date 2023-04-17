def distribute(num, num_buckets):
    g = num // num_buckets
    r = num % num_buckets
    for _ in range(num_buckets):
        if r > 0:
            yield g + 1
            r -= 1
        else:
            yield g

if __name__ == "__main__":
    print(list(distribute(10, 3)))
    print(list(distribute(10, 4)))
    print(list(distribute(20, 5)))
    print(list(distribute(23, 5)))