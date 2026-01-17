import os
import re
from datetime import datetime, timedelta
from collections import Counter, defaultdict

def get_db():
    db = defaultdict(list)
    h_re = re.compile(r"/\*\s*(.*?)\s*\n\s*\*\s*([A-Z][a-z]{2}\s\d{1,2},\s\d{4})")
    n_re = re.compile(r"/\*.*?\*/", re.DOTALL)
    for f in [f for f in os.listdir('.') if f.endswith('.cpp')]:
        try:
            with open(f, 'r', encoding='utf-8') as s:
                raw = s.read(2000)
                h = h_re.search(raw)
                if not h: continue
                ttl, d_str = h.group(1).strip(), h.group(2).strip()
                dt = datetime.strptime(d_str, "%b %d, %Y").date()
                blk = n_re.search(raw)
                n = []
                if blk:
                    for l in blk.group(0).split('\n'):
                        c = l.replace('/*', '').replace('*/', '').replace('*', '').strip()
                        if c and c not in (ttl, d_str): n.append(c)
                db[dt].append({'t': ttl, 'n': n, 'f': f"[{f}]"})
        except: continue
    return db

def glyph(n, ftr):
    return "*" if ftr else "░▒▓█"[(n > 0) + (n > 3) + (n > 8)]

def run():
    print("Activity log and heatmap provided by sc.py.\n\n")
    db = get_db()
    td = datetime.now().date()
    cnts = {k: len(v) for k, v in db.items()}
    start = td - timedelta(days=(td.weekday() + 1) % 7, weeks=29)
    grid = {d: [] for d in ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]}
    
    for i in range(210):
        curr = start + timedelta(days=i)
        grid[curr.strftime("%a")].append(glyph(cnts.get(curr, 0), curr > td))

    print("LAST-30-WEEK ACTIVITY HEATMAP:\n")
    for d in ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]:
        print(f"        {d} {' '.join(grid[d])}")
    
    ltst = max(db.keys() or [td])
    print(f"\n        Latest: {ltst}, ░:[0], ▒:(0,3], ▓:(3,8], █:(8,∞), *:Future")
    print(" " * 8 + "-" * 63 + "\n\n")

    for dt in sorted(db.keys(), reverse=True):
        print(f"{dt.strftime('%b %d, %Y')}:")
        for i in db[dt]:
            t_line = f"        {i['t']}"
            print(f"{t_line:<{80-len(i['f'])}}{i['f']}")
            if i['n']:
                print(f"        ╰─> {i['n'][0]}")
                for l in i['n'][1:]: print(f"            {l}")
                print()
        print()

if __name__ == "__main__":
    run()
