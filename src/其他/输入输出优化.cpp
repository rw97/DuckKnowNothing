namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;