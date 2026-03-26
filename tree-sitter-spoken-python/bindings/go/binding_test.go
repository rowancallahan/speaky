package tree_sitter_spoken_python_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-spoken_python"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_spoken_python.Language())
	if language == nil {
		t.Errorf("Error loading SpokenPython grammar")
	}
}
