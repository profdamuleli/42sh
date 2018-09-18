/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:37:46 by ngbanza           #+#    #+#             */
/*   Updated: 2017/10/01 13:45:34 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void		exec_cd(char *dir, int old_pwd_bool)
{
	char	*curr_dir;
	char	buff[BUFF_SIZE];
	char	*oldpwd;

	oldpwd = ft_getenv("$OLDPWD");
	curr_dir = getcwd(buff, BUFF_SIZE);
	set_env("OLDPWD", curr_dir);
	if (!chdir(dir))
	{
		if (old_pwd_bool)
			ft_putendl(oldpwd);
	}
	else
	{
		ft_putstr("cd :");
		if (access(dir, F_OK))
			ft_putstr(" no such file or directory: ");
		else if (access(dir, R_OK))
			ft_putstr(" permission denied: ");
		else
			ft_putstr(" not a directory");
		ft_putstr(dir);
		ft_putchar('\n');
	}
}

static int	tilder(char **dir, char *home, char *temp)
{
	temp = ft_strchr(dir[1], '~');
	home = ft_strjoin(home, "/");
	home = ft_strjoin(home, temp + 1);
	exec_cd(home, 0);
	free(temp);
	return (1);
}

int			exec_command_cd(char **dir)
{
	char	*home;
	char	*temp;

	temp = NULL;
	home = ft_getenv("$HOME");
	if (dir[1] && dir[2])
		ft_putendl("cd : too many arguments");
	else if (!dir[1] || !ft_strcmp(dir[1], "--"))
	{
		exec_cd(home, 0);
		return (1);
	}
	else if (dir[1][0] == '-')
	{
		home = ft_getenv("$OLDPWD");
		exec_cd(home, 1);
		return (1);
	}
	else if (dir[1][0] == '~')
		tilder(dir, home, temp);
	else
		exec_cd(dir[1], 0);
	return (1);
}
