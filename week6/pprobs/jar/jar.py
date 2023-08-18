
def main():
    jar = Jar()
    print(f'cookie jar capacity = ' + str(jar._capacity))

    jar.deposit(10)
    print(f"added 1 cookies, cookie count = " + str(jar))
    jar.withdraw(2)
    print(f"withdrew 1 cookie, cookie count = " + str(jar))









class Jar:
    def __init__(self, capacity=15):
        # is capacity < 0 raise error
        if capacity < 0:
            raise ValueError('wrong capacity')
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return self._size * '🍪'

    def deposit(self, n):
        if n > self._capacity:
            raise ValueError("Exceeds capacity")
        if self._size + n > self._capacity:
            raise ValueError('Exceeds capacity')
        self._size += n

    def withdraw(self, n):
        if self._size < n:
            raise ValueError("Not enough cookies in jar")
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size



if __name__ == "__main__":
	main()