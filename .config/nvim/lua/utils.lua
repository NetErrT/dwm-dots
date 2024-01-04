local M = {}

function M.set_keymaps(mode, keymaps, options)
	for key, command in pairs(keymaps) do
		vim.keymap.set(mode, key, command, options)
	end
end

function M.merge(left, right)
	for key, value in pairs(right) do
		left[key] = value
	end
end

return M
