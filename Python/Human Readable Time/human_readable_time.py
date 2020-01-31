t = 86399

def make_readable(seconds):
    time = seconds
    hours = time / (60 * 60)
    time = time % (60 * 60)
    mins = time / 60
    seconds = time % 60
    return "{:02d}:{:02d}:{:02d}".format(int(hours), int(mins), int(seconds))

print(make_readable(t))