local set_keymaps = require('utils').set_keymaps

set_keymaps('n', {
	['chl'] = function() vim.cmd('nohlsearch') end,
	['d['] = vim.diagnostic.goto_prev,
	['d]'] = vim.diagnostic.goto_next,
}, { noremap = true })
