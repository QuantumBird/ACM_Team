" 编码设置
set enc=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
 
" 语言设置
set helplang=cn
set encoding=utf8
set langmenu=zh_CN.UTF-8
set imcmdline
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

" 禁止生成临时文件
set nobackup
set noswapfile

" 不要生成swap文件，当buffer被丢弃的时候隐藏它
setlocal noswapfile
set bufhidden=hide

" 增强模式中的命令行自动完成操作
set wildmenu

" history文件中需要记录的行数
set history=100

" 在处理未保存或只读文件的时候，弹出确认
set confirm

" 侦测文件类型
filetype on

" 载入文件类型插件
filetype plugin on

" 为特定文件类型载入相关缩进文件
filetype indent on

" 语法高亮
syntax enable
set syntax=on

" 设置一行的最大长度
set textwidth=100

" 自动换行
set wrap

" 整词换行
set linebreak

" tab键的宽度
set tabstop=4

" 将tab转换为空格
set expandtab

" 统一缩进为4
set softtabstop=4
set shiftwidth=4

" 在行和段开始处使用制表符
set smarttab

" 显示行号
set number

" 使回格键（backspace）正常处理indent, eol, start等
set backspace=2

" 允许backspace和光标键跨越行边界
set whichwrap+=<,>,h,l

" 用浅色高亮当前行
if has("gui_running")
    autocmd
InsertLeave * se nocul
    autocmd
InsertEnter * se cul
endif

" 状态行颜色
highlight StatusLine guifg=SlateBlue guibg=Yellow
highlight StatusLineNC guifg=Gray guibg=White

" 搜索逐字符高亮
set incsearch

" 在搜索的时候忽略大小写
set ignorecase

