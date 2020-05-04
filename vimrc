This is my sample vimrc file.
color desert
set number
set nocompatible
set ic

set hlsearch
set incsearch
" syntax on
syntax enable

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

set history=50          " keep 50 lines of command line history
set ruler               " show the cursor position all the time
set showcmd             " display incomplete commands
set textwidth=70
set laststatus=2

" Set tab settings appropriate for source code editing.
set tabstop=4
set shiftwidth=4
set expandtab

filetype plugin indent on

" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  autocmd BufReadPost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \   exe "normal g`\"" |
    \ endif

  augroup END
else
  set autoindent
endif

map ; :

" Force cursor to be 'near' center of the screen after scrolling down.
set scrolljump=15

set background=dark
set cursorline
" highlight CursorLine ctermbg=pink

" Turn on autosave.
set autowrite

" Turn on paren high-lighting.
set showmatch

" use console mouse
set mouse=a
autocmd BufNewFile,BufRead *.yang set syntax=yang
autocmd BufNewFile,BufRead *.cli set syntax=xml
" autocmd BufWinLeave * mkview
" autocmd BufWinEnter * silent loadview
