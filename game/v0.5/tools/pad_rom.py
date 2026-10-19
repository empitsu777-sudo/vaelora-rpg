from pathlib import Path
p=Path(__file__).resolve().parents[1]/'build'/'vaelora_bellhaven_v05.gba'
b=p.read_bytes()
size=1<<(len(b)-1).bit_length()
if size<131072:size=131072
if size>16*1024*1024:raise SystemExit('ROM too large')
p.write_bytes(b+b'\xff'*(size-len(b)))
print('padded',len(b),'->',size)
