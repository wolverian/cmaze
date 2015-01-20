# maze

Learning C.

## Usage

	% maze/maze 51 15
	###################################################
	#   #         #   #     #   #   #                 #
	# # #         ### # #####   # ### ############### #
	# # #         #   #     #   # # #     #         # #
	# # ############# # #####   # # # #####         # #
	# # #       #   # #   # #   #   #     #         # #
	# # #       ### # # ### #   # ### ### #         # #
	# # #       #           #   # # #   # #         # #
	# # ######### ####### # ##### # # #################
	# #         #       # #       # #             #   #
	####### ##### ########### # ### # #############   #
	#     #                 # #   #   #     #   # #   #
	#     # # # # ########### ##### ### ##### ### #   #
	#     # # # #           #                     #   #
	###################################################


## Build

    ./build

## Description

Based on <http://journal.stuffwithstuff.com/2014/12/21/rooms-and-mazes/>.

## Progress

### Features

- [x] Carve rooms.
- [x] Join corridors/rooms.
- [ ] Prune corridors.

### Infrastructure

- [ ] Use native functions on OpenBSD.
- [ ] Run tests on Darwin too.
- [ ] abort() if malloc fails.
- [ ] Use arrays of inline objects instead of arrays of pointers.

## License

maze is available under the ISC license. See the LICENSE file for more information.
