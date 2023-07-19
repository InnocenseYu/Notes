def table(a, b):
    """九九乘法表"""
    for i in range(a, b):
        for j in range(a, b):
            print("%d * %d = %d" % (j, i, i*j), end="\t")
            if j == i:
                break
        print("")


table(1, 10)
