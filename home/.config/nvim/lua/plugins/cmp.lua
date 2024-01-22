return {
	'hrsh7th/nvim-cmp',
	event = { 'LspAttach' },
	config = function()
		local cmp = require('cmp')
		local luasnip = require('luasnip')

		cmp.setup({
			completion = {
				autocomplete = false,
			},
			snippet = {
				expand = function(args)
					luasnip.lsp_expand(args.body)
				end,
			},
			window = {
				completion = cmp.config.window.bordered(),
				documentation = cmp.config.window.bordered(),
			},
			mapping = cmp.mapping.preset.insert({
				['<C-b>'] = cmp.mapping.scroll_docs(-4),
				['<C-f>'] = cmp.mapping.scroll_docs(4),
				['<C-g>'] = cmp.mapping(function()
					if cmp.visible_docs() then
						cmp.close_docs()
					else
						cmp.open_docs()
					end
				end),
				['<C-Space>'] = cmp.mapping.complete(),
				['<C-j>'] = cmp.mapping(function()
					if cmp.visible() then
						cmp.select_next_item({ behavior = cmp.SelectBehavior.Select })
					elseif luasnip.expand_or_jumpable() then
						luasnip.expand_or_jump()
					end
				end, { 'i' }),
				['<C-k>'] = cmp.mapping(function()
					if cmp.visible() then
						cmp.select_prev_item({ behavior = cmp.SelectBehavior.Select })
					elseif luasnip.jumpable(-1) then
						luasnip.jump(-1)
					end
				end, { 'i' }),
				['<C-c>'] = cmp.mapping.close(),
				['<CR>'] = cmp.mapping.confirm({ select = false, behavior = cmp.ConfirmBehavior.Replace }),
			}),
			sources = cmp.config.sources(
				{
					{ name = 'nvim_lsp' }
				},
				{
					{ name = 'luasnip' }
				},
				{
					{ name = 'buffer' },
				}),
		})

		cmp.setup.filetype('gitcommit', {
			sources = cmp.config.sources({
				{ name = 'buffer' },
			})
		})

		cmp.setup.cmdline({ '/', '?' }, {
			mapping = cmp.mapping.preset.cmdline(),
			sources = cmp.config.sources(
				{
					{ name = 'buffer' }
				})
		})

		cmp.setup.cmdline(':', {
			mapping = cmp.mapping.preset.cmdline(),
			sources = cmp.config.sources(
				{
					{ name = 'path' }
				},
				{
					{ name = 'cmdline' }
				})
		})
	end,
	dependencies = {
		'hrsh7th/cmp-nvim-lsp',
		'L3MON4D3/LuaSnip',
		'hrsh7th/cmp-cmdline',
		'hrsh7th/cmp-path',
		'hrsh7th/cmp-buffer',
		'saadparwaiz1/cmp_luasnip',
	},
}
