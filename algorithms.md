# Algorithms in NanoRange #

## Fully implemented ##

The following algorithms are fully reimplemented in NanoRange,
meeting the requirements of the Ranges papers. In particular, they accept
iterators and sentinels of different types, and allow the use of projections.
In addition, they are all available for use in `constexpr` functions.

#### Non-modifying sequence operations ####

* all_of
* any_of
* none_of
* for_each
* find
* find_if
* find_if_not
* find_end
* find_first_of
* adjacent_find
* count
* count_if
* mismatch
* equal
* search
* search_n
* lexicographical_compare

#### Modifying sequence operations ####

* copy
* copy_n
* copy_if
* copy_backward
* move
* move_backward
* swap_ranges
* transform
* replace
* replace_if
* replace_copy
* replace_copy_if
* fill
* fill_n
* generate
* generate_n
* remove
* remove_if
* remove_copy
* remove_copy_if
* unique
* reverse
* reverse_copy
* rotate
* rotate_copy
* shuffle

#### Partition operations ####

* is_partitioned
* partition
* partition_copy
* partition_point

#### Sorting operations ####

* sort
* partial_sort
* partial_sort_copy
* is_sorted
* is_sorted_until

#### Binary search operations ####

* lower_bound
* upper_bound
* equal_range
* binary_search

#### Set operations ####

* merge
* includes
* set_union
* set_difference
* set_intersection
* set_symmetric_difference

#### Heap operations ####

* push_heap
* pop_heap
* make_heap
* sort_heap
* is_heap
* is_heap_until

#### Minimum and maximum operations ####

* min
* max
* minmax
* min_element
* max_element
* minmax_element

## Partially implemented (using STL) ##

The following algorithms are implemented in Nanorange as wrappers around the
existing standard library implementation. Constraints and return types are based
on the C++98 specification. This means that the iterator and sentinel types
must be the same, or for the range-based overloads, the range must model
CommonRange. Projections cannot be used.

#### Modifying sequence operations ####

* unique_copy

#### Partitioning operations ####

* stable_partition

#### Sorting operations ####

* stable_sort
* nth_element

#### Set operations ####

* inplace_merge

#### Permutation operations ####

* is_permutation
* next_permutation
* prev_permutation

