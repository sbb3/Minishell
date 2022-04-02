#include "source/source.h"
#include "strings_parser_and_vars_handler/strings_parser_and_vars_handler.h"


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


static t_env	*new_env(char *key, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->key = ft_strdup(key);
	env->value = ft_strdup(value);
	// env->key = key;
	// env->value = value;
	env->next = NULL;

	return (env);
}

static t_env	*initialize_env(void)
{
	t_env	*env;
	char	*env1[2] = {"USER", "root"};
	char	*env2[2] = {"PWD", "/home/jaw"};
	char	*env3[2] = {"jawad", "chakir"};
	char	*env4[2] = {"vv", "echo"};


	env = new_env(env1[0], env1[1]);
	lstaddback_env(env, new_env(env2[0], env2[1]));
	lstaddback_env(env, new_env(env3[0], env3[1]));
	lstaddback_env(env, new_env(env4[0], env4[1]));


	return (env);
}

static t_component	*initialize_component__11_(void)
{
	t_component *component;
	char		*comp1 = "jawad is the $USER";
	char		*comp2 = "'Single Quote: \"$USER\"'";
	char		*comp3 = "mkhalta \"Double Quotes: '{$PWD}'\" [$jawad] '$jawad' $$ $12  $?";
	char		*comp4 = "Simple and Double Quotes: \"$USER\"";
	char		*comp5 = "$vv";

	component = NULL;

	component = new_component(comp1, 0);
	lstaddback_component(component, new_component(comp2, 0));
	lstaddback_component(component, new_component(comp3, 0));
	lstaddback_component(component, new_component(comp4, 0));
	lstaddback_component(component, new_component(comp5, 0));

	return (component);

}

static t_shell	*initialize_shell_struct(void)
{
	t_shell 	*shell;

	shell = malloc(sizeof(t_shell));
	shell->separator = malloc(sizeof(t_component *));
	shell->separator[0] = initialize_component__11_();
	shell->envp = initialize_env();
	shell->exit_status = 100;
	shell->parts_count = 1;

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


static void	print_all_components(t_component *component)
{
	while (component)
	{
		printf("[%s]\n", component->content);
		component = component->next;
	}
}


int main(void)
{
	t_shell 	*shell;

	shell = initialize_shell_struct();


	strings_parser_and_vars_handler(shell);


	print_all_components(shell->separator[0]);
	
	// system("leaks testvars");

	return 0;


}
