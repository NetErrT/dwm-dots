local merge = require('utils').merge

local options = {
	sync_install = false,
	auto_install = false,
	highlight = {
		enable = true,
	},
	indent = {
		enable = true,
	},
	incremental_selection = {
		enable = true,
		keymaps = {
			init_selection = 'ti',
			node_incremental = 'tn',
			scope_incremental = 'ts',
			node_decremental = 'tN',
		},
	},
}

return {
	'nvim-treesitter/nvim-treesitter',
	event = { 'BufRead', 'BufNewFile' },
	build = ':TSUpdate',
	config = function()
		merge(vim.opt, {
				foldmethod = 'expr',
				foldexpr = 'nvim_treesitter#foldexpr()',
		})

		require('nvim-treesitter.configs').setup(options)
	end
}
