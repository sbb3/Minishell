

#include "source/source.h"
#include "strings_parser_and_vars_handler/strings_parser_and_vars_handler.h"
#include "commands_executor/commands_executor.h"
#include "builtin_commands/builtin_commands.h"



void	lstaddback_component(t_component *list, t_component *new)
{
	while (list->next)
		list = list->next;
	list->next = new;
}


void	lstaddback_env(t_env *list, t_env *new)
{
	while (list->next)
		list = list->next;
	list->next = new;
}


static t_component *new_component(char *content, int type)
{
	t_component *component;

	component = malloc(sizeof(t_component));
	component->content = ft_strdup(content);
	// component->content = content;
	component->type = type;
	component->next = NULL;
	return component;
}

static t_env	*initialize_env(void)
{
	t_env	*env;
	char	*env1[2] = {"USER", "root"};
	char	*env2[2] = {"PWD", "/home/jaw"};
	char	*env3[2] = {"HOME", "/Users/jchakir"};
	char	*env4[2] = {"PATH", "/Users/jchakir/.brew/bin:/goinfre/jchakir/java/bin:/goinfre/jchakir/py/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/jchakir/.brew/bin:/goinfre/jchakir/java/bin:/goinfre/jchakir/py/bin:/Applications/Visual Studio Code.app/Contents/Resources/app/bin:/Applications/Visual Studio Code.app/Contents/Resources/app/bin"};
	char	*env5[2] = {"OLDPWD", "/Users/jchakir/py"};


	env = new_env(env1[0], env1[1]);
	lstaddback_env(env, new_env(env2[0], env2[1]));
	lstaddback_env(env, new_env(env3[0], env3[1]));
	lstaddback_env(env, new_env(env4[0], env4[1]));
	lstaddback_env(env, new_env(env5[0], env5[1]));


	return (env);
}

static t_component	*initialize_component__11_(void)
{
	t_component *component;
	char		*comp1 = "echo";
	char		*comp2 = "tttttttttffffffff";
	// char		*comp3 = "-e";
	// char		*comp4 = "jawad";
	// char		*comp5 = "out";

	component = NULL;

	component = new_component(comp1, ARGS);
	lstaddback_component(component, new_component(comp2, ARGS));
	// lstaddback_component(component, new_component(comp3, ARGS));
	// lstaddback_component(component, new_component(comp4, ARGS));
	// lstaddback_component(component, new_component(comp5, OUTFILE));

	return (component);

}

static t_component	*initialize_component__22_(void)
{
	t_component *component;
	char		*comp1 = "Makefile";
	char		*comp2 = "cat";
	// char		*comp3 = "out";
	// char		*comp4 = "out1";
	// char		*comp5 = "out1";

	component = NULL;

	component = new_component(comp1, INFILE);
	lstaddback_component(component, new_component(comp2, ARGS));
	// lstaddback_component(component, new_component(comp3, INFILE));
	// lstaddback_component(component, new_component(comp4, OUTFILE));
	// lstaddback_component(component, new_component(comp5, OUTFILE_APPEND));

	return (component);

}

static t_component	*initialize_component__33_(void)
{
	t_component *component;
	char		*comp1 = "cat";
	char		*comp2 = "-e";
	// char		*comp3 = "out5";
	// char		*comp4 = "/bin/test";

	component = NULL;

	component = new_component(comp1, ARGS);
	lstaddback_component(component, new_component(comp2, ARGS));
	// lstaddback_component(component, new_component(comp3, OUTFILE));
	// lstaddback_component(component, new_component(comp4, OUTFILE));

	return (component);

}


static t_component	*initialize_component__44_(void)
{
	t_component *component;
	char		*comp1 = "wc";
	// char		*comp2 = "-kkkk";
	// char		*comp3 = "out";
	// char		*comp4 = "out1";
	char		*comp5 = "/bin/test";

	component = NULL;

	component = new_component(comp1, ARGS);
	// lstaddback_component(component, new_component(comp2, ARGS));
	// lstaddback_component(component, new_component(comp3, INFILE));
	// lstaddback_component(component, new_component(comp4, OUTFILE));
	lstaddback_component(component, new_component(comp5, OUTFILE_APPEND));

	return (component);

}


static t_shell	*initialize_shell_struct(void)
{
	t_shell *shell;
	int		parts_count = 4;

	shell = malloc(sizeof(t_shell));
	shell->separator = malloc(sizeof(t_component *) * parts_count);
	shell->separator[0] = initialize_component__11_();
	shell->separator[1] = initialize_component__22_();
	shell->separator[2] = initialize_component__33_();
	shell->separator[3] = initialize_component__44_();
	shell->envp = initialize_env();
	shell->exit_status = 100;
	shell->parts_count = parts_count;
	shell->pids = NULL;
	shell->pipefds = NULL;

	return (shell);
}


// static void	print_all_envs(t_env *env)
// {
// 	while (env)
// 	{
// 		printf("%s : %s\n", env->key, env->value);
// 		env = env->next;
// 	}
// }


// static void	print_all_components(t_component *component)
// {
// 	while (component)
// 	{
// 		printf("%s\n", component->content);
// 		component = component->next;
// 	}
// }


int main(int argc, char **argv)
{
	t_shell 	*shell;

	shell = initialize_shell_struct();

	(void)argc;
	(void)argv;

	// shell->parts_count = 3;

	commands_executor(shell);



	// system("leaks test");

	// printf("pid = %d\n", getpid());
	// while (1) {}

	// printf(" return status : %d\n", shell->exit_status);

	return shell->exit_status;
}
