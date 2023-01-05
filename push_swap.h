/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 23:27:49 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/02 23:27:49 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// An integer in one of the stacks.
typedef struct s_item {
	int				value;
	int				intended_index;
	struct s_item	*next;
	struct s_item	*prev;
}	t_item;

// A single instruction performed on the stack and logged for printing. Values
// of action and target should be read using the e_action and e_target enums.
typedef struct s_instruction {
	int						action;
	int						target;
	struct s_instruction	*next;
	struct s_instruction	*prev;
}	t_instruction;

// Main struct containing the stacks and a log of the instructions so far.
// The stacks have been modeled as doubly linked lists of items. By passing
// the struct to other functions, the "state" of the program can be maintained
// throughout.
//
// @param stack_a      Stack a, the one which starts off with all command line
//                     arguments in the given order and should end with all
//                     elements sorted in ascending order.
// @param stack_b      Stack b, swap space during operation that needs to be
//                     completely empty at the end.
// @param instructions A linked list of executed instructions, for ease of
//                     printing them at the end.
typedef struct s_push_swap {
	t_item			*stack_a;
	t_item			*stack_b;
	t_instruction	*instructions;
}	t_push_swap;

// An enum containing the different sorting operations available to us. Used
// to determine which actions have been performed when printing the entire
// instruction set at the end.
typedef enum e_action {
	action_swap,
	action_push,
	action_rotate,
	action_reverse_rotate
}	t_action;

// An enum containing different targets for a sorting operation. Used to
// determine which of the stacks to operate on, or which instruction to
// print in the terminal at the end.
typedef enum e_target {
	target_a,
	target_b,
	target_double
}	t_target;

//== VALIDATIONS ==//

void			run_arg_validations(char *str);
int				only_atoi_characters(char *str);

//== PREPARING THE STACK ==//

void			initialize_stack(t_push_swap *push_swap, char **input, \
									int count);
void			add_to_bottom_of_stack_a(t_push_swap *push_swap, t_item *item);

//== MANUAL SORT ALGORITHM ==//

void			run_manual_sort(t_push_swap *push_swap);
void			determine_intended_indices(t_push_swap *push_swap);
int				index_in_stack(t_item *item, t_item *stack);
t_item			*bubble_sort_stack(t_item *stack);

//== PUSH_SWAP INSTRUCTION HANDLERS ==//
// These functions are how operations are called on the stack and logged
// for printing later on.

void			swap(t_push_swap *push_swap, int target);
void			push(t_push_swap *push_swap, int target);
void			rotate(t_push_swap *push_swap, int target);
void			reverse_rotate(t_push_swap *push_swap, int target);

//== PUSH_SWAP INSTRUCTION EXECUTERS ==//
// These functions actually perform the instructions, changing the order and
// updating the pointers.

void			perform_swap(t_item **stack);
void			perform_push(t_item **src, t_item **dest);
void			perform_rotate(t_item **stack);
void			perform_reverse_rotate(t_item **stack);

//== LOGGING AND PRINTING ==//
// These functions keep track of performed operations and print them at the end
// in the format specified by the subject.

void			log_instruction(t_push_swap *push_swap, int action, int target);
void			print_string_for_instruction(t_instruction *instruction);

//== STRUCT MANAGEMENT FUNCTIONS ==//
// These functions copy and free the push_swap and stack structs.

void			free_push_swap_struct(t_push_swap *push_swap);
void			free_item_stack(t_item *stack);
void			free_instruction_list(t_instruction *list);

t_push_swap		*copy_push_swap_struct(t_push_swap *push_swap);
t_item			*copy_item_stack(t_item *stack);
t_instruction	*copy_instruction_list(t_instruction *list);

//== DEBUG FUNCTIONS ==//
// These functions print what's happening under the hood into stdout.

void			print_stacks(t_push_swap *push_swap);
int				count_stack_items(t_item *stack);
void			print_stack(t_item *stack);
int				count_instructions(t_instruction *instruction);
void			print_instructions_debug(t_instruction *instruction);

#endif
