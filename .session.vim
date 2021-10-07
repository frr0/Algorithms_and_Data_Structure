let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +8 Labs/Lab00/Ex1/.vimspector.json
badd +1 Labs/Lab00/Ex1/client.c
badd +9 Labs/Lab00/Ex1/client.h
badd +6 Labs/Lab00/Ex1/f1.txt
badd +1 Labs/Lab00/Ex1/f2.txt
badd +1 Labs/Lab00/Ex1/Makefile
badd +46 Labs/Lab00/Ex1/util.c
badd +16 Labs/Lab00/Ex1/util.h
argglobal
%argdel
$argadd Labs/Lab00/Ex1/.vimspector.json
$argadd Labs/Lab00/Ex1/client.c
$argadd Labs/Lab00/Ex1/client.h
$argadd Labs/Lab00/Ex1/f1.txt
$argadd Labs/Lab00/Ex1/f2.txt
$argadd Labs/Lab00/Ex1/Makefile
$argadd Labs/Lab00/Ex1/util.c
$argadd Labs/Lab00/Ex1/util.h
set stal=2
tabnew
tabnew
tabnew
tabrewind
edit Labs/Lab00/Ex1/client.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 84 + 85) / 170)
exe 'vert 2resize ' . ((&columns * 85 + 85) / 170)
argglobal
if bufexists("Labs/Lab00/Ex1/client.c") | buffer Labs/Lab00/Ex1/client.c | else | edit Labs/Lab00/Ex1/client.c | endif
if &buftype ==# 'terminal'
  silent file Labs/Lab00/Ex1/client.c
endif
balt Labs/Lab00/Ex1/.vimspector.json
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
let s:l = 1 - ((0 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/client.h") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/client.h | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/client.h | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/client.h
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/client.c
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
let s:l = 1 - ((0 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
exe 'vert 1resize ' . ((&columns * 84 + 85) / 170)
exe 'vert 2resize ' . ((&columns * 85 + 85) / 170)
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 85 + 85) / 170)
exe 'vert 2resize ' . ((&columns * 84 + 85) / 170)
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.c") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.c | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.c | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.c
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.h
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
let s:l = 1 - ((0 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.h") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.h | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.h | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.h
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/util.c
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
let s:l = 16 - ((11 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 16
normal! 0
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
exe 'vert 1resize ' . ((&columns * 85 + 85) / 170)
exe 'vert 2resize ' . ((&columns * 84 + 85) / 170)
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/Makefile
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
exe 'vert 1resize ' . ((&columns * 84 + 85) / 170)
exe '2resize ' . ((&lines * 19 + 21) / 43)
exe 'vert 2resize ' . ((&columns * 85 + 85) / 170)
exe '3resize ' . ((&lines * 20 + 21) / 43)
exe 'vert 3resize ' . ((&columns * 85 + 85) / 170)
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/Makefile") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/Makefile | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/Makefile | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/Makefile
endif
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
let s:l = 8 - ((5 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 8
normal! 011|
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f1.txt") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f1.txt | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f1.txt | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f1.txt
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/client.h
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
let s:l = 1 - ((0 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f2.txt") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f2.txt | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f2.txt | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f2.txt
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/f1.txt
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
let s:l = 1 - ((0 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
wincmd w
exe 'vert 1resize ' . ((&columns * 84 + 85) / 170)
exe '2resize ' . ((&lines * 19 + 21) / 43)
exe 'vert 2resize ' . ((&columns * 85 + 85) / 170)
exe '3resize ' . ((&lines * 20 + 21) / 43)
exe 'vert 3resize ' . ((&columns * 85 + 85) / 170)
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure/Labs/Lab00/Ex1/.vimspector.json
argglobal
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
let s:l = 8 - ((5 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 8
normal! 041|
lcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/Algorithms_and_Data_Structure
tabnext 2
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOFcI
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
