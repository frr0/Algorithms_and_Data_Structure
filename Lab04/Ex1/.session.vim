let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab04/Ex1
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +2 .vimspector.json
badd +1 client.c
badd +1 f1.txt
badd +5 f2.txt
badd +3 Makefile
argglobal
%argdel
$argadd .vimspector.json
$argadd client.c
$argadd f1.txt
$argadd f2.txt
$argadd Makefile
set stal=2
tabnew
tabrewind
edit client.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 99 + 119) / 239)
exe 'vert 2resize ' . ((&columns * 98 + 119) / 239)
exe 'vert 3resize ' . ((&columns * 40 + 119) / 239)
argglobal
if bufexists("client.c") | buffer client.c | else | edit client.c | endif
if &buftype ==# 'terminal'
  silent file client.c
endif
balt .vimspector.json
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 69 - ((24 * winheight(0) + 29) / 59)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 69
normal! 027|
wincmd w
argglobal
if bufexists("client.c") | buffer client.c | else | edit client.c | endif
if &buftype ==# 'terminal'
  silent file client.c
endif
balt .vimspector.json
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 28 - ((27 * winheight(0) + 29) / 59)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 28
normal! 05|
wincmd w
argglobal
enew
file __Tagbar__.1
balt .vimspector.json
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
wincmd w
exe 'vert 1resize ' . ((&columns * 99 + 119) / 239)
exe 'vert 2resize ' . ((&columns * 98 + 119) / 239)
exe 'vert 3resize ' . ((&columns * 40 + 119) / 239)
tabnext
edit f1.txt
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 79 + 119) / 239)
exe '2resize ' . ((&lines * 28 + 31) / 62)
exe 'vert 2resize ' . ((&columns * 79 + 119) / 239)
exe '3resize ' . ((&lines * 28 + 31) / 62)
exe 'vert 3resize ' . ((&columns * 79 + 119) / 239)
exe '4resize ' . ((&lines * 30 + 31) / 62)
exe 'vert 4resize ' . ((&columns * 159 + 119) / 239)
argglobal
if bufexists("f1.txt") | buffer f1.txt | else | edit f1.txt | endif
if &buftype ==# 'terminal'
  silent file f1.txt
endif
balt client.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 5 - ((4 * winheight(0) + 29) / 59)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 5
normal! 012|
wincmd w
argglobal
if bufexists("f2.txt") | buffer f2.txt | else | edit f2.txt | endif
if &buftype ==# 'terminal'
  silent file f2.txt
endif
balt f1.txt
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 5 - ((4 * winheight(0) + 14) / 28)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 5
normal! 018|
wincmd w
argglobal
if bufexists(".vimspector.json") | buffer .vimspector.json | else | edit .vimspector.json | endif
if &buftype ==# 'terminal'
  silent file .vimspector.json
endif
balt f1.txt
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 2 - ((1 * winheight(0) + 14) / 28)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
wincmd w
argglobal
if bufexists("Makefile") | buffer Makefile | else | edit Makefile | endif
if &buftype ==# 'terminal'
  silent file Makefile
endif
balt f2.txt
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 9 - ((8 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 9
normal! 014|
wincmd w
exe 'vert 1resize ' . ((&columns * 79 + 119) / 239)
exe '2resize ' . ((&lines * 28 + 31) / 62)
exe 'vert 2resize ' . ((&columns * 79 + 119) / 239)
exe '3resize ' . ((&lines * 28 + 31) / 62)
exe 'vert 3resize ' . ((&columns * 79 + 119) / 239)
exe '4resize ' . ((&lines * 30 + 31) / 62)
exe 'vert 4resize ' . ((&columns * 159 + 119) / 239)
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=ifncTFtOolxI
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
