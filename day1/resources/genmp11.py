#!/usr/bin/env python

with open('input.txt', 'r') as f:
    data = f.read().split('\n\n')

mp_list_elems = list()

mp_list_elems.append('#include <boost/mp11/algorithm.hpp>')
mp_list_elems.append('#include <boost/mp11/list.hpp>')
mp_list_elems.append('#include <fmt/core.h>')

mp_list_elems.append('using namespace boost::mp11;')
for elf, line in enumerate(data):
    out = f'using Elf{elf} = mp_list<'
    out += ',\n'.join([f'std::integral_constant<int, {item}>' for item in line.split('\n')])
    out += '>;'
    mp_list_elems.append(out)

mp_list_elems.append('using Elves = mp_list<' +  ', '.join([f'Elf{i}' for i in range(len(data))]) + '>;')

mp_list_elems.append('''
template <typename L>
using sum = mp_fold<L, std::integral_constant<int, 0>, mp_plus>;

using ElfCalories = mp_transform<sum, Elves>;
using MaxCalories = mp_max_element<ElfCalories, mp_less>;
''')

with open('mp11_embed.hpp', 'w') as f:
    f.write('\n'.join(mp_list_elems))
