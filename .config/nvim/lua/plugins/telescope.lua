local set_keymaps = require('utils').set_keymaps

local options = function()
	local actions = require('telescope.actions')

	return {
		defaults = {
			mappings = {
				i = {
					['<esc>'] = actions.close,
				},
			},
		},
	}
end

return {
	'nvim-telescope/telescope.nvim',
	lazy = false,
	dependencies = {
		'nvim-lua/plenary.nvim',
	},
	config = function()
		local telescope = require('telescope')
		local builtin = require('telescope.builtin')

		telescope.setup(options())

		set_keymaps('n', {
			['<leader>ff'] = builtin.find_files,
			['<leader>fb'] = builtin.buffers,
		}, {})
	end
}
