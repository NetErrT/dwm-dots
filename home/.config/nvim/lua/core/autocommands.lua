local set_keymaps = require('utils').set_keymaps

local autocmd = vim.api.nvim_create_autocmd

autocmd('LspAttach', {
	callback = function(event)
		vim.bo[event.buf].omnifunc = 'v:lua.vim.lsp.omnifunc'

		set_keymaps('n', {
			['gD'] = vim.lsp.buf.declaration,
			['gd'] = vim.lsp.buf.definition,
			['gi'] = vim.lsp.buf.implementation,
			['gr'] = vim.lsp.buf.references,
			['gh'] = vim.lsp.buf.hover,
			['gs'] = vim.lsp.buf.signature_help,
			['<leader>wa'] = vim.lsp.buf.add_workspace_folder,
			['<leader>wr'] = vim.lsp.buf.remove_workspace_folder,
			['<leader>wl'] = function()
				print(vim.inspect(vim.lsp.buf.list_workspace_folders()))
			end,
			['<leader>td'] = vim.lsp.buf.type_definition,
			['<leader>rn'] = vim.lsp.buf.rename,
			['<leader>ca'] = vim.lsp.buf.code_action,
			['<leader>fm'] = function()
				vim.lsp.buf.format({ async = true })
			end,
		}, { buffer = event.buf, noremap = true })

		set_keymaps('v', {
			['<leader>ca'] = vim.lsp.buf.code_action,
		}, { buffer = event.buf, noremap = true });
	end,
})
