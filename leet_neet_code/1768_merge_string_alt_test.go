package leetneet 

import (
    "testing"
)

type TestCase = struct {
    word1 string
    word2 string
    solution string
}

func TestMergeAlternately(t *testing.T) {
    test := []TestCase  {
        {"abc", "pqr", "apbqcr"},
        {"ab", "pqrs", "apbqrs"},
        {"abcd", "pq", "apbqcd"},
    }
    
    for i := 0; i < len(test); i++ {
        word1 := test[i].word1
        word2 := test[i].word2
        solution := test[i].solution
        res := mergeAlternately(word1, word2)
        if res != solution  {
            t.Errorf("mergeAlternately(%s, %s) != %s but %s",
                word1, 
                word2, 
                solution, 
                res)
        }
    }
}
