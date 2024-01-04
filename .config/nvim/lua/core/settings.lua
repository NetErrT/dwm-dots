local opt = vim.opt
local merge = require('utils').merge

merge(opt, {
	tabstop = 2,
	shiftwidth = 2,
	smartcase = true,
	clipboard = 'unnamedplus',
	completeopt = 'menuone',
	relativenumber = true,
	swapfile = false,
	wrap = true,
	timeoutlen = 400,
	undofile = true,
	smarttab = true,
	termguicolors = true,
	cursorline = true,
	foldlevel = 10,
	foldenable = true,
	autochdir = false,
	fileencoding = 'utf-8',
	fileformat = 'unix',
	history = 20,
	numberwidth = 2,
	signcolumn = 'no',
	splitbelow = true,
	splitright = true,
	copyindent = true,
})

opt.matchpairs:append('<:>')

merge(vim.g, {
	mapleader = ' ',
})

vim.diagnostic.config({
	underline = true,
	virtual_text = {
		source = 'if_many',
		spacing = 2,
	},
	severity_sort = true,
})
