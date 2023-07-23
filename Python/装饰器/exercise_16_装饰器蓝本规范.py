from functools import wraps
# 解决 print(func.__name__) 是 decorated 不是 func 的问题

def decorator_name(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        if not can_run:
            return "Function will not run"
        return f(*args, **kwargs)

    return decorated


@decorator_name
def func():
    return "Function is running"


can_run = True
print(func())
# Output: Function is running

# can_run = False
# print(func())
# Output: Function will not run
