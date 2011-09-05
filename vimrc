set expandtab tabstop=4 shiftwidth=4 foldmethod=marker
syntax on
colorscheme default
"set background=dark
set hls
set cindent
set autoindent
set number
set guifont=Monospace\ 9

function! GuiTabLabel()
    " add the tab number
    let label = '['.tabpagenr()
 
    " modified since the last save?
    let buflist = tabpagebuflist(v:lnum)
    for bufnr in buflist
        if getbufvar(bufnr, '&modified')
            let label .= '*'
            break
        endif
    endfor
 
    " count number of open windows in the tab
    let wincount = tabpagewinnr(v:lnum, '$')
    if wincount > 1
        let label .= ', '.wincount
    endif
    let label .= '] '
 
    " add the file name without path information
    let n = bufname(buflist[tabpagewinnr(v:lnum) - 1])
    let label .= fnamemodify(n, ':t')
 
    return label
endfunction
 
set guitablabel=%{GuiTabLabel()}

