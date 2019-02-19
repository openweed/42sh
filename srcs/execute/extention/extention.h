/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:55 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/16 17:51:59 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENTION_H
# define EXTENTION_H

/*
** ${parameter:-word} 1
** ${parameter:=word} 2
** ${parameter:?word} 3
** ${parameter:+word} 4
** ${#parameter}      5  
** ${parameter%}      6  
** ${parameter%%}     7  
** ${parameter#}      8  
** ${parameter##}     9  
*/

char	*get_content_of_expression(char *str);

#endif