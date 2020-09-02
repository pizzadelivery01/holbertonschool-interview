#!/usr/bin/python3
"""
log parsing stdin
"""
if __name__ == '__main__':
    import sys

    def parse_stdin(size, status):
        """
       reads stdin line by line and computes metrics
        """
        print("File size: {}".format(total_size))

        for key, value in sorted(status.items()):
            if value != 0:
                print("{}: {}".format(key, value))

    total_size = 0
    i = 0

    status = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    try:
        for line in sys.stdin:
            word = line.split()

            try:
                code = word[-2]
                if code in status.keys():
                    status[code] += 1
            except BaseException:
                pass

            try:
                size = word[-1]
                size = int(size)
                total_size += size
            except BaseException:
                pass

            i += 1

            if (i == 10):
                parse_stdin(total_size, status)
                i = 0

        parse_stdin(total_size, status)
    except KeyboardInterrupt:
        parse_stdin(total_size, status)
        raise
