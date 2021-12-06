let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +22 client.c
badd +2 f.txt
badd +2 Makefile
badd +12 util/util.h
badd +1 util/util.c
badd +3 client.h
badd +25 ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/lab08.txt
badd +133 lab07-BSTLibrary/tree.c
badd +21 lab07-BSTLibrary/treePublic.h
badd +4 lab07-BSTLibrary/treePrivate.h
badd +0 lab07-BSTLibrary/client.c
badd +17 util/data/data.c
badd +0 util/data/data.h
argglobal
%argdel
$argadd Makefile
set stal=2
tabnew
tabnew
tabnew
tabnew
tabrewind
edit client.c
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
exe '2resize ' . ((&lines * 7 + 22) / 45)
exe 'vert 2resize ' . ((&columns * 85 + 85) / 170)
exe '3resize ' . ((&lines * 33 + 22) / 45)
exe 'vert 3resize ' . ((&columns * 85 + 85) / 170)
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
let s:l = 22 - ((21 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 22
normal! 06|
wincmd w
argglobal
if bufexists("client.h") | buffer client.h | else | edit client.h | endif
if &buftype ==# 'terminal'
  silent file client.h
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
let s:l = 3 - ((2 * winheight(0) + 3) / 7)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 023|
wincmd w
argglobal
if bufexists("lab07-BSTLibrary/client.c") | buffer lab07-BSTLibrary/client.c | else | edit lab07-BSTLibrary/client.c | endif
if &buftype ==# 'terminal'
  silent file lab07-BSTLibrary/client.c
endif
balt client.h
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
let s:l = 19 - ((0 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 19
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 84 + 85) / 170)
exe '2resize ' . ((&lines * 7 + 22) / 45)
exe 'vert 2resize ' . ((&columns * 85 + 85) / 170)
exe '3resize ' . ((&lines * 33 + 22) / 45)
exe 'vert 3resize ' . ((&columns * 85 + 85) / 170)
if exists(':tcd') == 2 | tcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1 | endif
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/util.c
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
let s:l = 32 - ((30 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 32
normal! 0
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/util.h") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/util.h | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/util.h | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/util.h
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/util.c
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
let s:l = 12 - ((11 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 12
normal! 037|
wincmd w
exe 'vert 1resize ' . ((&columns * 85 + 85) / 170)
exe 'vert 2resize ' . ((&columns * 84 + 85) / 170)
if exists(':tcd') == 2 | tcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1 | endif
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/tree.c
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
exe 'vert 1resize ' . ((&columns * 85 + 85) / 170)
exe '2resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 2resize ' . ((&columns * 84 + 85) / 170)
exe '3resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 3resize ' . ((&columns * 84 + 85) / 170)
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
let s:l = 133 - ((26 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 133
normal! 07|
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePublic.h") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePublic.h | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePublic.h | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePublic.h
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/tree.c
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
let s:l = 17 - ((16 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 17
normal! 013|
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePrivate.h") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePrivate.h | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePrivate.h | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/treePrivate.h
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/lab07-BSTLibrary/tree.c
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
let s:l = 4 - ((3 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 4
normal! 021|
wincmd w
exe 'vert 1resize ' . ((&columns * 85 + 85) / 170)
exe '2resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 2resize ' . ((&columns * 84 + 85) / 170)
exe '3resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 3resize ' . ((&columns * 84 + 85) / 170)
if exists(':tcd') == 2 | tcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1 | endif
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.c
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
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.c
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
let s:l = 1 - ((0 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.h") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.h | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.h | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.h
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/util/data/data.c
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
let s:l = 1 - ((0 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 85 + 85) / 170)
exe 'vert 2resize ' . ((&columns * 84 + 85) / 170)
if exists(':tcd') == 2 | tcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1 | endif
tabnext
edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/lab08.txt
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
exe 'vert 1resize ' . ((&columns * 87 + 85) / 170)
exe '2resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 2resize ' . ((&columns * 82 + 85) / 170)
exe '3resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 3resize ' . ((&columns * 82 + 85) / 170)
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
let s:l = 25 - ((0 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 25
normal! 0
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/lab08.txt
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
let s:l = 9 - ((8 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 9
normal! 012|
wincmd w
argglobal
if bufexists("~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile") | buffer ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile | else | edit ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile | endif
if &buftype ==# 'terminal'
  silent file ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1/Makefile
endif
balt ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/lab08.txt
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
let s:l = 9 - ((8 * winheight(0) + 10) / 20)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 9
normal! 012|
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 87 + 85) / 170)
exe '2resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 2resize ' . ((&columns * 82 + 85) / 170)
exe '3resize ' . ((&lines * 20 + 22) / 45)
exe 'vert 3resize ' . ((&columns * 82 + 85) / 170)
if exists(':tcd') == 2 | tcd ~/Dropbox\ (Politecnico\ Di\ Torino\ Studenti)/Anno_II.1/ADS/Algorithms_and_Data_Structure/Lab08/Ex1 | endif
tabnext 5
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOFcI
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
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
