local servers = {
	tsserver = {
		keys = {
			{
				"<leader>toi",
				function()
					vim.lsp.buf.code_action({
						apply = true,
						context = {
							only = { "source.organizeImports.ts" },
							diagnostics = {},
						},
					})
				end,
				desc = "Organize Imports",
			},
			{
				"<leader>tru",
				function()
					vim.lsp.buf.code_action({
						apply = true,
						context = {
							only = { "source.removeUnused.ts" },
							diagnostics = {},
						},
					})
				end,
				desc = "Remove Unused Imports",
			},
		},
		settings = {
			typescript = {
				format = {
					indentSize = vim.o.shiftwidth,
					convertTabsToSpaces = vim.o.expandtab,
					tabSize = vim.o.tabstop,
				},
				inlayHints = {
					includeInlayParameterNameHints = 'literal',
					includeInlayParameterNameHintsWhenArgumentMatchesName = false,
					includeInlayFunctionParameterTypeHints = true,
					includeInlayVariableTypeHints = false,
					includeInlayPropertyDeclarationTypeHints = true,
					includeInlayFunctionLikeReturnTypeHints = true,
					includeInlayEnumMemberValueHints = true,
				},
			},
			javascript = {
				format = {
					indentSize = vim.o.shiftwidth,
					convertTabsToSpaces = vim.o.expandtab,
					tabSize = vim.o.tabstop,
				},
				inlayHints = {
					includeInlayParameterNameHints = 'all',
					includeInlayParameterNameHintsWhenArgumentMatchesName = false,
					includeInlayFunctionParameterTypeHints = true,
					includeInlayVariableTypeHints = true,
					includeInlayPropertyDeclarationTypeHints = true,
					includeInlayFunctionLikeReturnTypeHints = true,
					includeInlayEnumMemberValueHints = true,
				},

			},
			completions = {
				completeFunctionCalls = true,
			},
		},
	},
	lua_ls = {},
	clangd = {
		cmd = {
			"clangd",
			"--background-index",
			"--clang-tidy",
			"--header-insertion=iwyu",
			"--completion-style=detailed",
			"--function-arg-placeholders",
			"--fallback-style=llvm",
		},
		init_options = {
			usePlaceholders = true,
			completeUnimported = false,
			clangdFileStatus = true,
		},
	},
	jsonls = {
		settings = {
			json = {
				format = {
					enable = true,
				},
				validate = { enable = true },
			},
		},
	},
	yamlls = {},
	cssls = {},
	html = {
		cmd = { 'vscode-html-language-server', '--stdio' },
		init_options = {
			configurationSection = { 'html', 'css', 'javascript' },
			embeddedLanguages = {
				css = true,
				javascript = true
			},
			provideFormatter = true
		},
	},
}

return {
	'neovim/nvim-lspconfig',
	event = { 'BufRead', 'BufNewFile' },
	config = function()
		local lspconfig = require('lspconfig')
		local capabilities = vim.lsp.protocol.make_client_capabilities()
		capabilities.textDocument.completion.completionItem.snippetSupport = true

		for server, options in pairs(servers) do
			options.capabilities = capabilities

			lspconfig[server].setup(options)
		end
	end
}
